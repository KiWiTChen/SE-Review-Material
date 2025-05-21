package controller;

import java.awt.AWTEvent;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

@SuppressWarnings("serial")
public class GradeEnter extends JFrame implements ActionListener {
  /*
   * 教师录入成绩
   */
  String idd; // 教师号
  JPanel contain;
  JLabel id;
  JTextField idt, stuIdt, stuGradet, stuNamet;

  String targetFile;

  JButton submit, bn;
  ArrayList<String> modifiedContent = new ArrayList<>();

  public GradeEnter(String idd) {
    super("查看");
    this.idd = idd;
    setSize(300, 340);
    setLocation(600, 400);
    contain = new JPanel();
    contain.setLayout(null);
    add(contain);
    id = new JLabel("课程号");
    idt = new JTextField();
    submit = new JButton("提交");
    id.setBounds(38, 50, 75, 35);
    idt.setBounds(80, 50, 150, 35);
    submit.setBounds(102, 125, 70, 30);
    contain.add(id);
    contain.add(idt);
    contain.add(submit);
    submit.addActionListener(this);
    setVisible(true);
    enableEvents(AWTEvent.WINDOW_EVENT_MASK);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == submit) {
      if (hasThisCourse(idt.getText()) == 1) {
        enter(); // 进入成绩输入界面

      }
      else {
        JOptionPane.showMessageDialog(null, "您未开设此课程！", "提示", JOptionPane.INFORMATION_MESSAGE);
      }
    }
    else if (e.getSource() == bn) {

      if (hasThisStu() == 1) { // 登陆成绩

        String path = System.getProperty("user.dir") + "/data/grade";
        // String path = "D://test//grade";

        // 找对应课程成绩文件
        List<String> files = new ArrayList<>(); // 课程成绩目录下所有科目成绩文件
        File file = new File(path);
        File[] tempList = file.listFiles();

        for (File element : tempList) {
          if (element.isFile()) {
            files.add(element.toString());
            // 文件名，不包含路径
            // String fileName = tempList[i].getName();
          }
          if (element.isDirectory()) {
            // 这里就不递归了，
          }
        }

        try {
          for (String file2 : files) { // 遍历所有文件
            BufferedReader br = new BufferedReader(new FileReader(file2));
            String s = null;
            String[] result = null;
            while ((s = br.readLine()) != null) {// 使用readLine方法，对一个文件一次读一行
              result = s.split(" ");
              if (result[0].equals(idt.getText())) { // 开始改写成绩文件
                targetFile = file2;

                // 将原来的内容先复制
                String s1 = "";
                for (int j = 0; j < result.length - 1; j++) {
                  s1 = s1 + result[j];
                  s1 = s1 + " ";
                }
                s1 = s1 + result[result.length - 1];

                modifiedContent.add(s1);

              }
            } // 读完一个成绩文件

            if (result[0].equals(idt.getText())) {
              String gradeInfo = idt.getText();
              gradeInfo = gradeInfo + " ";
              gradeInfo = gradeInfo + result[1];
              gradeInfo = gradeInfo + " ";
              gradeInfo = gradeInfo + result[2];
              gradeInfo = gradeInfo + " ";
              gradeInfo = gradeInfo + result[3];
              gradeInfo = gradeInfo + " ";
              gradeInfo = gradeInfo + stuIdt.getText();
              gradeInfo = gradeInfo + " ";
              gradeInfo = gradeInfo + stuNamet.getText();
              gradeInfo = gradeInfo + " ";
              gradeInfo = gradeInfo + stuGradet.getText();
              modifiedContent.add(gradeInfo);
            }

            br.close();
          }
        }
        catch (Exception ee) {
          ee.printStackTrace();
        }

        try {
          FileWriter fw = new FileWriter(targetFile);
          BufferedWriter bw = new BufferedWriter(fw);

          for (String element : modifiedContent) {
            bw.write(element);
            bw.newLine();
          }

          bw.close();
          fw.close();
        }
        catch (IOException e1) {
          // TODO Auto-generated catch block
          e1.printStackTrace();
        }

        JOptionPane.showMessageDialog(null, "成绩登录成功！", "提示", JOptionPane.INFORMATION_MESSAGE);

      }
      else {
        JOptionPane.showMessageDialog(null, "课程号为" + idt.getText() + "无此学生", "提示", JOptionPane.INFORMATION_MESSAGE);
      }
    }
  }

  int hasThisStu() {

    @SuppressWarnings("unused")
    String stuId = stuIdt.getText();

    String path = System.getProperty("user.dir") + "/data/course_student";
    // String path = "D://test//course_student";

    List<String> files = new ArrayList<>(); // 目录下所有文件
    File file = new File(path);
    File[] tempList = file.listFiles();

    for (File element : tempList) {
      if (element.isFile()) {
        files.add(element.toString());
        // 文件名，不包含路径
        // String fileName = tempList[i].getName();
      }
      if (element.isDirectory()) {
        // 这里就不递归了，
      }
    }

    try {
      for (String file2 : files) {
        BufferedReader br = new BufferedReader(new FileReader(file2));
        String s = null;
        while ((s = br.readLine()) != null) {// 使用readLine方法，一次读一行
          String[] result = s.split(" ");
          if (result[0].equals(idt.getText()) && result[2].equals(stuIdt.getText())) {
            br.close();
            return 1;
          }
        }
        br.close();
      }
    }
    catch (Exception e) {
      e.printStackTrace();
    }

    return 0;
  }

  void enter() {
    JFrame fm = new JFrame("登录成绩");
    fm.setSize(300, 340);
    JPanel contain = new JPanel();
    fm.setLocation(600, 400);
    contain.setLayout(null);
    bn = new JButton("提交");
    JLabel stuId = new JLabel("学号");
    JLabel stuGrade = new JLabel("成绩");
    JLabel stuName = new JLabel("姓名");

    stuIdt = new JTextField();
    stuGradet = new JTextField();
    stuNamet = new JTextField();

    stuId.setBounds(38, 50, 75, 35);
    stuIdt.setBounds(80, 50, 150, 35);

    stuGrade.setBounds(38, 110, 75, 35);
    stuGradet.setBounds(80, 110, 150, 35);

    stuName.setBounds(38, 170, 75, 35);
    stuNamet.setBounds(80, 170, 150, 35);

    bn.setBounds(170, 220, 70, 30);
    contain.add(stuId);
    contain.add(stuIdt);
    contain.add(stuGrade);
    contain.add(stuGradet);
    contain.add(stuName);
    contain.add(stuNamet);
    contain.add(bn);
    fm.add(contain);
    bn.addActionListener(this);
    fm.setVisible(true);

  }

  int hasThisCourse(String idd) {

    String file = System.getProperty("user.dir") + "/data/course.txt";
    // String file = "D://test//course.txt";
    try {
      BufferedReader br = new BufferedReader(new FileReader(file));
      String s = null;
      while ((s = br.readLine()) != null) {// 使用readLine方法，一次读一行
        String[] result = s.split(" ");
        if (result[0].equals(idd)) {
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

  @Override
  public void processWindowEvent(WindowEvent e) {
    if (e.getID() == WindowEvent.WINDOW_CLOSING) {
      this.dispose();
      setVisible(false);
    }
  }
}
