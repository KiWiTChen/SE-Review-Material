package model;

import static org.junit.Assert.*;
import org.junit.Test;

public class UserTest {

    @Test
    public void testUserAttributes() {
        ConcreteUser user = new ConcreteUser("001", "password", "John Doe");
        assertEquals("001", user.getId()); // ��֤�û�ID�Ƿ�Ϊ"001"
        assertEquals("password", user.getPwd()); // ��֤�û������Ƿ�Ϊ"password"
        assertEquals("John Doe", user.getName()); // ��֤�û����Ƿ�Ϊ"John Doe"
    }
}
