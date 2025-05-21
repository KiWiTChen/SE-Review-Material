package controller;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.After;
import org.junit.Test;

import java.io.*;

public class CheckInfoTest {

    private CheckInfo checkInfo;
    private String testDataPath;

    @Before
    public void setUp() throws Exception {
        checkInfo = new CheckInfo();
        // ָ�����������ļ���·��
        testDataPath = System.getProperty("user.dir") + "/data/testData.txt";
        // �������������ļ���д������
        createTestDataFile();
    }

    @After
    public void tearDown() throws Exception {
        // ɾ�����������ļ�
        new File(testDataPath).delete();
    }

    private void createTestDataFile() throws IOException {
        // ʹ��BufferedWriter��д���������
        BufferedWriter writer = new BufferedWriter(new FileWriter(testDataPath));
        writer.write("a 123456\n");
        writer.write("a1 1234567\n");
        writer.write("a3 123\n");
        writer.close();
    }

    @Test
    public void testIsMemberUserAndPasswordCorrect() throws Exception {
        // �����û�a������123456
        int result = checkInfo.isMember("testData", "a", "123456");
        assertEquals(1, result);
    }

    @Test
    public void testIsMemberUserExistsPasswordIncorrect() throws Exception {
        // �����û�a1���������
        int result = checkInfo.isMember("testData", "a1", "wrongpassword");
        assertEquals(2, result);
    }

    @Test
    public void testIsMemberUserDoesNotExist() throws Exception {
        // ���Բ����ڵ��û�
        int result = checkInfo.isMember("testData", "nonExistingUser", "anyPassword");
        assertEquals(0, result);
    }

    @Test
    public void testIsMemberFileException() {
        // �����ļ������ڵ����
        int result = checkInfo.isMember("nonExistingTable", "anyUser", "anyPassword");
        assertEquals(0, result);
    }
}