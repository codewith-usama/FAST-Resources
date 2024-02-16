abstract class SubjectContent {
    protected String subjectName;

    public String getSubjectName() {
        return subjectName;
    }

    public abstract void updateSubjectContent();
}

class Subject extends SubjectContent {
    @Override
    public void updateSubjectContent() {
        // Update subject content implementation
        System.out.println("Subject content updated.");
    }
}

interface TeacherInterface {
    String getTeacherName();

    String getSubjectTeaching();

    void listenToQuestions();

    void answerToStudentQuestion();
}

class Teacher extends SubjectContent implements TeacherInterface {
    private String teacherName;
    private Subject subjectTeaching;

    public Teacher(String teacherName, Subject subjectTeaching) {
        this.teacherName = teacherName;
        this.subjectTeaching = subjectTeaching;
    }

    @Override
    public String getTeacherName() {
        return teacherName;
    }

    @Override
    public String getSubjectTeaching() {
        return subjectTeaching.getSubjectName();
    }

    @Override
    public void listenToQuestions() {
        System.out.println(teacherName + " is listening to student questions.");
    }

    @Override
    public void answerToStudentQuestion() {
        System.out.println(teacherName + " is answering student questions.");
    }

    @Override
    public void updateSubjectContent() {
        // Update subject content implementation for teacher
        System.out.println("Subject content updated by the teacher.");
    }
}

interface SubjectHeadInterface {
    String getSubjectHeadName();

    void updateSubjectContent();
}

class SubjectHead extends SubjectContent implements SubjectHeadInterface {
    private String subjectHeadName;

    public SubjectHead(String subjectHeadName) {
        this.subjectHeadName = subjectHeadName;
    }

    @Override
    public String getSubjectHeadName() {
        return subjectHeadName;
    }

    @Override
    public void updateSubjectContent() {
        // Update subject content implementation for subject head
        System.out.println("Subject content updated by the subject head.");
    }
}

class Student extends Subject {
    private String studentName;
    private String classStandard;

    public Student(String studentName, String classStandard) {
        this.studentName = studentName;
        this.classStandard = classStandard;
    }

    public String getStudentName() {
        return studentName;
    }

    public String getStudentClass() {
        return classStandard;
    }

    public void askQuestion() {
        System.out.println(studentName + " is asking a question.");
    }

    public void listenToProfessor() {
        System.out.println(studentName + " is listening to the teacher.");
    }
}
