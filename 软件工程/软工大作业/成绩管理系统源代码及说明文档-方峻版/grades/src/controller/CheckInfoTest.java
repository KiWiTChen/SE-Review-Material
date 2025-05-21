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
        // 指定测试数据文件的路径
        testDataPath = System.getProperty("user.dir") + "/data/testData.txt";
        // 创建测试数据文件并写入内容
        createTestDataFile();
    }

    @After
    public void tearDown() throws Exception {
        // 删除测试数据文件
        new File(testDataPath).delete();
    }

    private void createTestDataFile() throws IOException {
        // 使用BufferedWriter来写入测试数据
        BufferedWriter writer = new BufferedWriter(new FileWriter(testDataPath));
        writer.write("a 123456\n");
        writer.write("a1 1234567\n");
        writer.write("a3 123\n");
        writer.close();
    }

    @Test
    public void testIsMemberUserAndPasswordCorrect() throws Exception {
        // 测试用户a和密码123456
        int result = checkInfo.isMember("testData", "a", "123456");
        assertEquals(1, result);
    }

    @Test
    public void testIsMemberUserExistsPasswordIncorrect() throws Exception {
        // 测试用户a1，密码错误
        int result = checkInfo.isMember("testData", "a1", "wrongpassword");
        assertEquals(2, result);
    }

    @Test
    public void testIsMemberUserDoesNotExist() throws Exception {
        // 测试不存在的用户
        int result = checkInfo.isMember("testData", "nonExistingUser", "anyPassword");
        assertEquals(0, result);
    }

    @Test
    public void testIsMemberFileException() {
        // 测试文件不存在的情况
        int result = checkInfo.isMember("nonExistingTable", "anyUser", "anyPassword");
        assertEquals(0, result);
    }
}