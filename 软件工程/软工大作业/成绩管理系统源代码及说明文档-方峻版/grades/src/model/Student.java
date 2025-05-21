package model;


public class Student extends User {

	private String sex;
	private String birthday;
	private String institute;
	private String major;
	
	
	
	public Student() {
		super();
	}


	public Student(String id, String pwd, String name, String sex,
			String birthday, String institute, String major) {
		super(id, pwd, name);
		this.sex = sex;
		this.birthday = birthday;
		this.institute = institute;
		this.major = major;
	}
	
	
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getBirthday() {
		return birthday;
	}
	public void setBirthday(String birthday) {
		this.birthday = birthday;
	}
	public String getInstitute() {
		return institute;
	}
	public void setInstitute(String institute) {
		this.institute = institute;
	}
	public String getMajor() {
		return major;
	}
	public void setMajor(String major) {
		this.major = major;
	}

	
}
