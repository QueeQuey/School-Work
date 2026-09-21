package decorator;

import java.lang.reflect.Constructor;

public class MRTestUtils {
	public static String checkSingleton(String clsName) {
		String errMsg = null;
		try {
			Class<?> cls = Class.forName(clsName);
			Constructor[] arrayOfConstructor = (Constructor[])cls.getConstructors();
			if (arrayOfConstructor.length > 0)
				errMsg = clsName + " must not have a public constructor.";
		} catch (Exception e) {
			errMsg = " Unexpected exception: " + e + " with cause " + e.getCause();
		}
		return errMsg;
	}
}
