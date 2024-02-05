import 'dart:io';

void main() {
  var calculateFrequency = CalculateFrequency();
  calculateFrequency.analyzeTextFile();
  calculateFrequency.calculateHighestFrequencyLine();
  calculateFrequency.printResult();
}

class CalculateFrequency {
  late List<String> lines;
  late Map<String, int> highestFrequencyWords;

  void analyzeTextFile() {
    var file = File('file.txt');
    lines = file.readAsLinesSync();
    highestFrequencyWords = {};

    for (var line in lines) {
      var words = line.split(' ');
      var wordFrequencyMap = <String, int>{};

      for (var word in words) {
        wordFrequencyMap[word] = (wordFrequencyMap[word] ?? 0) + 1;
      }

      wordFrequencyMap.forEach((word, frequency) {
        if (!highestFrequencyWords.containsKey(word) ||
            highestFrequencyWords[word]! < frequency) {
          highestFrequencyWords[word] = frequency;
        }
      });
    }
  }

  void calculateHighestFrequencyLine() {}

  void printResult() {
    print('The following words have the highest word frequency per line:');
    for (var lineNumber = 0; lineNumber < lines.length; lineNumber++) {
      var line = lines[lineNumber];
      var words = line.split(' ');

      var highestFrequencyWordsInLine = <String>[];
      var wordFrequencyMap = <String, int>{};

      for (var word in words) {
        wordFrequencyMap[word] = (wordFrequencyMap[word] ?? 0) + 1;
      }

      var maxFrequency = 0;
      wordFrequencyMap.forEach((word, frequency) {
        if (frequency > maxFrequency) {
          maxFrequency = frequency;
          highestFrequencyWordsInLine = [word];
        } else if (frequency == maxFrequency) {
          highestFrequencyWordsInLine.add(word);
        }
      });

      print(
          '${highestFrequencyWordsInLine} (appears in line ${lineNumber + 1})');
    }

    var linesWithHighestFrequencyWords = <int>[];
    for (var line in lines) {
      var words = line.split(' ');
      var wordFrequencyMap = <String, int>{};

      for (var word in words) {
        wordFrequencyMap[word] = (wordFrequencyMap[word] ?? 0) + 1;
      }

      var hasHighestFrequencyWords = words.every(
          (word) => highestFrequencyWords[word] == wordFrequencyMap[word]);
      if (hasHighestFrequencyWords) {
        linesWithHighestFrequencyWords.add(lines.indexOf(line) + 1);
      }
    }

    print(
        'Lines with the highest frequency words: $linesWithHighestFrequencyWords');
  }
}
