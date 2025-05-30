package model;

import static org.junit.Assert.*;

import org.junit.Test;

public class ModelIntegrationTest {

	@Test
    public void testAdministrator() {
        Administrator admin = new Administrator("A001", "adminPass", "Admin Name", "Male", "1980-01-01", "Admin Institute", "Admin Major");
        assertEquals("A001", admin.getId());
        assertEquals("adminPass", admin.getPwd());
        assertEquals("Admin Name", admin.getName());
        assertEquals("Male", admin.getSex());
        assertEquals("1980-01-01", admin.getBirthday());
        assertEquals("Admin Institute", admin.getInstitute());
        assertEquals("Admin Major", admin.getMajor());
    }

    @Test
    public void testStudent() {
        Student student = new Student("S001", "studentPass", "Student Name", "Female", "2000-01-01", "Student Institute", "Student Major");
        assertEquals("S001", student.getId());
        assertEquals("studentPass", student.getPwd());
        assertEquals("Student Name", student.getName());
        assertEquals("Female", student.getSex());
        assertEquals("2000-01-01", student.getBirthday());
        assertEquals("Student Institute", student.getInstitute());
        assertEquals("Student Major", student.getMajor());
    }

    @Test
    public void testTeacher() {
        Teacher teacher = new Teacher("T001", "teacherPass", "Teacher Name", "Male", "1975-01-01", "Teacher Institute", "Teacher Major");
        assertEquals("T001", teacher.getId());
        assertEquals("teacherPass", teacher.getPwd());
        assertEquals("Teacher Name", teacher.getName());
        assertEquals("Male", teacher.getSex());
        assertEquals("1975-01-01", teacher.getBirthday());
        assertEquals("Teacher Institute", teacher.getInstitute());
        assertEquals("Teacher Major", teacher.getMajor());
    }
    
    @Test
    public void testCourseConstruction() {
        // 创建Course对象
        Course course = new Course("CS101", "Introduction to Computer Science", "T001", "Teacher Name", "3", "45");

        // 验证Course对象的属性
        assertEquals("CS101", course.getCourseId());
        assertEquals("Introduction to Computer Science", course.getCourseName());
        assertEquals("T001", course.getTeacherId());
        assertEquals("Teacher Name", course.getTeacherName());
        assertEquals("3", course.getCredit());
        assertEquals("45", course.getHour());
    }
}


