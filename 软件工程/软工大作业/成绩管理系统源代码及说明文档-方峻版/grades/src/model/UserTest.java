package model;

import static org.junit.Assert.*;
import org.junit.Test;

public class UserTest {

    @Test
    public void testUserAttributes() {
        ConcreteUser user = new ConcreteUser("001", "password", "John Doe");
        assertEquals("001", user.getId()); // 验证用户ID是否为"001"
        assertEquals("password", user.getPwd()); // 验证用户密码是否为"password"
        assertEquals("John Doe", user.getName()); // 验证用户名是否为"John Doe"
    }
}
