package model;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class Course {

  private String courseId;
  private String courseName;
  private String teacherId;
  private String teacherName;
  private String credit;
  private String hour;
  private float fail, pass, good, excellent;// 占比

  public Course(String courseId, float pass, float good, float excellent) {
    super();
    this.courseId = courseId;
    this.pass = pass;
    this.good = good;
    this.excellent = excellent;
  }

  public Course(String courseId, String courseName, String teacherId, String teacherName, String credit, String hour) {

    this.courseId = courseId;
    this.courseName = courseName;
    this.teacherId = teacherId;
    this.teacherName = teacherName;
    this.credit = credit;
    this.hour = hour;
  }

  public Course(String courseId, String courseName, String teacherId, String teacherName, float fail, float pass,
      float good, float excellent) {

    this.courseId = courseId;
    this.courseName = courseName;
    this.teacherId = teacherId;
    this.teacherName = teacherName;
    this.fail = fail;
    this.pass = pass;
    this.good = good;
    this.excellent = excellent;
  }

  public String getCourseId() {
    return courseId;
  }

  public void setCourseId(String courseId) {
    this.courseId = courseId;
  }

  public String getCourseName() {
    return courseName;
  }

  public void setCourseName(String courseName) {
    this.courseName = courseName;
  }

  public String getTeacherId() {
    return teacherId;
  }

  public void setTeacherId(String teacherId) {
    this.teacherId = teacherId;
  }

  public String getTeacherName() {
    return teacherName;
  }

  public void setTeacherName(String teacherName) {
    this.teacherName = teacherName;
  }

  public float getFial() {
    return fail;
  }

  public void setFial(float fial) {
    this.fail = fial;
  }

  public float getPass() {
    return pass;
  }

  public void setPass(float pass) {
    this.pass = pass;
  }

  public float getGood() {
    return good;
  }

  public void setGood(float good) {
    this.good = good;
  }

  public float getExcellent() {
    return excellent;
  }

  public void setExcellent(float excellent) {
    this.excellent = excellent;
  }

  public String getCredit() {
    return credit;
  }

  public void setCredit(String credit) {
    this.credit = credit;
  }

  public String getHour() {
    return hour;
  }

  public void setHour(String hour) {
    this.hour = hour;
  }

  public float getFail() {
    return fail;
  }

  public void setFail(float fail) {
    this.fail = fail;
  }

  // 判断course.txt是否存在
  public int hasCourse() {
    String file = System.getProperty("user.dir") + "/data/course.txt";
    // String file = "D://test//course.txt";
    try {
      BufferedReader br = new BufferedReader(new FileReader(file));
      String s = null;
      while ((s = br.readLine()) != null) {// 使用readLine方法，一次读一行
        String[] result = s.split(" ");
        if (result[0].equals(this.courseId)) {
          br.close();
          return 1;
        }
      }
      br.close();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
    return 0;
  }

  // 统计各分数段学生人数
  public int[] sortGrade() {
    int failCount = 0, passCount = 0, goodCount = 0, excellentCount = 0;

    String path = System.getProperty("user.dir") + "/data/grade";

    List<String> fileNameList = new ArrayList<>(); // 目录下所有文件
    File filePath = new File(path);
    File[] fileDirArray = filePath.listFiles();// java没有Directory类

    for (File element : fileDirArray) {
      if (element.isFile()) {
        fileNameList.add(element.toString());
        // 文件名，不包含路径
        // String fileName = tempList[i].getName();
      }
      if (element.isDirectory()) {

      }
    }

    BufferedReader br = null;
    String targetFile = null;

    // 寻找对应本课程的成绩文件（其实直接通过文件名判断不更快捷？）
    try {
      for (String fileName : fileNameList) {
        br = new BufferedReader(new FileReader(fileName));
        String s = null;
        if ((s = br.readLine()) != null) {
          String[] result = s.split(" ");
          if (result[0].equals(this.courseId)) {
            targetFile = fileName;
            break;
          }
        }
        br.close();
      }
    }
    catch (Exception e) {
      e.printStackTrace();
    }

    try {
      br = new BufferedReader(new FileReader(targetFile));
      String s = null;
      while ((s = br.readLine()) != null) {
        String[] result = s.split(" ");
        if (Float.parseFloat(result[6]) < this.pass) {
          failCount += 1;
        }
        else if (Float.parseFloat(result[6]) < this.good) {
          passCount += 1;
        }
        else if (Float.parseFloat(result[6]) < this.excellent) {
          goodCount += 1;
        }
        else {
          excellentCount += 1;
        }
      }
      br.close();
    }
    catch (Exception e) {
      e.printStackTrace();
    }

    return new int[] { failCount, passCount, goodCount, excellentCount };
  }

  public int isValidate() { // 输入的成绩标准是否是在正常内[0, 100],以及pass<good<excellent
    if (this.pass < 0 || this.pass > 100 || this.good < 0 || this.good > 100 || this.excellent < 0
        || this.excellent > 100 || this.pass >= good || this.pass >= excellent || this.good >= excellent) {
      return 1;
    }
    return 0;
  }

}
