package controller;

import model.Course;

public class GradeSort {
  /*
   * 教师查询成绩统计结果
   */

  String courseId;
  float pass, good, excellent; // 及格，优良，优秀
  Course course;

  public GradeSort(String courseId, float pass, float good, float excellent) {

    this.course = new Course(courseId, pass, good, excellent);
  }

  public int hasCourse() {
    return this.course.hasCourse();
  }

  public int[] sortGrade() {

    return this.course.sortGrade();
  }

  public int isValidate() { // 输入的成绩标准是否是在正常内[0, 100],以及pass<good<excellent
    return this.course.isValidate();
  }

}
