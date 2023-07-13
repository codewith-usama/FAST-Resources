import os
import math
import numpy as np
import nltk
from nltk.corpus import wordnet
from nltk.stem import PorterStemmer
import tkinter as tk
from tkinter import *
from tkinter import scrolledtext


stemmer = PorterStemmer()
# read stopwords from file
stopwords = []
with open('Stopword-List.txt', 'r') as f:
    stopwords = f.read().splitlines()

# function to preprocess text
#removes punctuation and convert to lowercase, then remove stop words from the list
#then performend stemming 
def preprocess(text):
    text = ''.join([c.lower() for c in text if c.isalpha() or c.isspace()])
    tokens = nltk.word_tokenize(text)
    tokens = [word for word in tokens if word not in stopwords]
    stems = [stemmer.stem(lemma) for lemma in tokens]
    text = ' '.join(stems)
    return text

# read dataset and preprocess it, one file is read at a time
dataset = {}
for filename in os.listdir(r'Dataset'):
    with open(os.path.join('Dataset', filename), 'r') as f:
        text = f.read()
        dataset[filename] = preprocess(text)

# create vocabulary and inverted index
vocabulary = set()
inverted_index = {}
for document_id, text in dataset.items():
    for word in text.split():
        if word not in stopwords:
            stem = stemmer.stem(word)
            vocabulary.add(stem)
            if stem not in inverted_index:
                inverted_index[stem] = {}
            if document_id not in inverted_index[stem]:
                inverted_index[stem][document_id] = 0
            inverted_index[stem][document_id] += 1

# calculate IDF for each word
word_idf = {}
for word in vocabulary:
    count = len(inverted_index[word])
    word_idf[word] = math.log(len(dataset) / count)

# calculate tf-idf for each document
doc_tfidf = {}
for document_id, text in dataset.items():
    word_tf = {}
    for word in text.split():
        if word not in stopwords:
            stem = stemmer.stem(word)
            word_tf[stem] = word_tf.get(stem, 0) + 1
    word_tfidf = {}
    for word, tf in word_tf.items():
        word_tfidf[word] = tf * word_idf[word]
    doc_tfidf[document_id] = word_tfidf

        
# function to calculate cosine similarity between two vectors, the user query vector and document vector 
def vector_cosine_similairty(vector1, vector2):
    nm = sum([vector1.get(word,0) * vector2.get(word, 0) for word in set(vector1.keys()) & set(vector2.keys())])
    dm = math.sqrt(sum([vector1.get(word, 0) ** 2 for word in vector1.keys()]) * sum([vector2.get(word, 0) ** 2 for word in vector2.keys() ]))
    if dm == 0:
        return 0.0
    else:
        return nm / dm 

# process user_query
while True:
    user_query = input("Enter user_query: ")
    if user_query.lower() == "exit":
        break
    

    user_query = preprocess(user_query)
    query_tf = {}
    for word in user_query.split():
        if word not in stopwords:
            stem = stemmer.stem(word)
            if stem in inverted_index:
                count = len(inverted_index[stem])
                tf = query_tf.get(stem, 0)+ 1
                query_tf[stem] = tf
    query_tfidf = {}
    for word, tf in query_tf.items():
        query_tfidf[word] = tf * word_idf[word]

# calculate cosine similarity between query vector and document vectors
    final_results = []
    for document_id, doc_vector in doc_tfidf.items():
        similarity = vector_cosine_similairty(query_tfidf, doc_vector)
        if similarity > 0.05: #threshold  set for search final_results 
            final_results.append((document_id, similarity))

# sort final_results by cosine similarity in descending order
    final_results = sorted(final_results, key=lambda x: x[1], reverse=True)

    
    
    for result in final_results:
	    print(result[0] + "-->" +str(result[1]))
