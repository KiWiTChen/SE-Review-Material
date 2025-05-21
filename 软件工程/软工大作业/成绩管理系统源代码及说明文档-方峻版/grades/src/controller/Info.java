package controller;

import java.awt.AWTEvent;
import java.awt.GridLayout;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.FileReader;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import model.*;

public class Info extends JFrame {    
	/**
	 * 用户查询个人信息
	 */
	private static final long serialVersionUID = 1L;
	JLabel idLabel, nameLabel, genderLabel, birLabel, insLabel, majorLabel;
	String id, name, pwd, gender, birthday, institute, major;
	JPanel stuInfoJPanel;
	
	Student stu;
	Teacher t;

	public Info(String id, int flag) {
		super("信息");
		this.id = id;
		setSize(300, 340);
		setLocation(600, 400);
		stuInfoJPanel = new JPanel();
		stuInfoJPanel.setLayout(new GridLayout(20, 1));
		add(stuInfoJPanel);
		String file = "";
		if (flag==1){
			// file = "D://test//student.txt";
			file = System.getProperty("user.dir")+"/data/student.txt";
		}
		else{
			// file = "D://test//teacher.txt";
			file = System.getProperty("user.dir")+"/data/teacher.txt";
		}
		
		 //StringBuilder result = new StringBuilder();
	        try{
	            BufferedReader br = new BufferedReader(new FileReader(file));//构造一个BufferedReader类来读取文件
	            String s = null;
	            while((s = br.readLine())!=null){//使用readLine方法，一次读一行
	            	String[] result = s.split(" ");
	            	if(result[0].equals(id)){
	            		id = result[0];
	            		pwd = result[1];
	            		name = result[2];
	            		gender = result[3];
	            		birthday = result[4];
	            		institute = result[5];
	            		major = result[6];
	            		
	            		if(flag == 1){
	            			stu = new Student(id, pwd, name, gender, birthday, institute, major);
	            			idLabel = new JLabel("账号:" + stu.getId());
	            			nameLabel = new JLabel("姓名:" + stu.getName());
	            			genderLabel = new JLabel("性别:" + stu.getSex());
	            			birLabel = new JLabel("生日:" + stu.getBirthday());
	            			insLabel = new JLabel("学院:" + stu.getInstitute());
	            			majorLabel = new JLabel("系别:" + stu.getMajor());
	            		}else{
	            			t = new Teacher(id, pwd, name, gender, birthday, institute, major);
	            			idLabel = new JLabel("账号:" + t.getId());
	            			nameLabel = new JLabel("姓名:" + t.getName());
	            			genderLabel = new JLabel("性别:" + t.getSex());
	            			birLabel = new JLabel("生日:" + t.getBirthday());
	            			insLabel = new JLabel("学院:" + t.getInstitute());
	            			majorLabel = new JLabel("系别:" + t.getMajor());
	            		}
	            		
	            	}
	            }
	            br.close();    
	        }catch(Exception e){
	            e.printStackTrace();
	        }
	

		stuInfoJPanel.add(idLabel);
		stuInfoJPanel.add(nameLabel);
		stuInfoJPanel.add(genderLabel);
		stuInfoJPanel.add(birLabel);
		stuInfoJPanel.add(insLabel);
		stuInfoJPanel.add(majorLabel);
		enableEvents(AWTEvent.WINDOW_EVENT_MASK);
		setVisible(true);
		
	}

	public void processWindowEvent(WindowEvent e) {
		if (e.getID() == WindowEvent.WINDOW_CLOSING) {
			this.dispose();
			setVisible(false);
		}
	}
}
