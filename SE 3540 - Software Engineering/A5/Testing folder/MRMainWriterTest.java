package decorator;

import java.io.IOException;
import java.io.Writer;
import java.util.Random;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvFileSource;

@DisplayName("Remote test class for MR Writer to ROT13 code")
class Remote_MRMainWriterTest {
	MRMain am;

	char[] buf;

	private final int bufsize = 10;

	String methodCall;

	@BeforeEach
	void setup() {
		this.am = new MRMain();
		Assertions.assertNotNull(this.am, "Could not instantiate MRMain with default constructor.");
		this.buf = new char[10];
	}

	@DisplayName("Initial test method with 'Why me' string")
	@Test
	void testROT13_2() {
		String input = "Why me?";
		String expected = "Jul zr?";
		Writer strWR = this.am.getROT13Writer();
		Assertions.assertNotNull(strWR, "ROT13 writer is null");
		try {
			strWR.write(input);
			String result = strWR.toString();
			Assertions.assertEquals(expected, result);
		} catch (IOException e) {
			Assertions.fail("ROT13 writer threw Exception " + e + " with cause: " + e.getCause());
		}
	}


	@DisplayName("Test writecbuf, int off, int len) from random string")
	@ParameterizedTest
	@CsvFileSource(resources = {"/rot13IO.csv"})
	public void testWriteFromArray(String expected, String original) {
		Writer strWR = this.am.getROT13Writer();
		Assertions.assertNotNull(strWR, "ROT13 writer is null");
		int lenPar = original.length();
		Random randg = new Random((expected.length() % 10));
		int offset = randg.nextInt(lenPar / 2);
		int len = randg.nextInt(lenPar / 2);
		char[] src = original.toCharArray();
		String expectedStr = expected.substring(offset, offset + len);
		String methodCall = "write(char[], " + offset + ", " + len + ")";
		try {
			strWR.write(src, offset, len);
			String stRes = strWR.toString();
			Assertions.assertEquals(expectedStr, stRes, methodCall + " from source '" + methodCall + "'" + original + "-=- ACTUAL : '" + System.lineSeparator() + "'" + stRes + "-=- EXPECTED: '" + System.lineSeparator() + "'" + expectedStr);
		} catch (Exception e) {
			Assertions.fail("ROT13Writer threw Exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- When doing: " + methodCall + " from source '" + original + "'" + System.lineSeparator() + "-=- Expected: '" + expectedStr + "'" + System.lineSeparator());
		}
	}

	@DisplayName("Negative offset")
	@Test
	void testROT13Off() {
		Writer strWR = this.am.getROT13Writer();
		Assertions.assertNotNull(strWR, "ROT13 writer is null");
		this.methodCall = "write(char[10], -1, 2)";
		try {
			strWR.write(this.buf, -1, 2);
		} catch (IndexOutOfBoundsException e) {
			return;
		} catch (Exception e) {
			Assertions.fail("ROT13 method call " + this.methodCall + System.lineSeparator() + "-=- ACTUAL: exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- Expected: IndexOutOfBoundsException " + System.lineSeparator());
		}
		Assertions.fail("ROT13 method call " + this.methodCall + System.lineSeparator() + "-=- ACTUAL: no exception" + System.lineSeparator() + "-=- Expected: IndexOutOfBoundsException " + System.lineSeparator());
	}

	@DisplayName("Negative length")
	@Test
	void testROT13Len() {
		Writer strWR = this.am.getROT13Writer();
		Assertions.assertNotNull(strWR, "ROT13 writer is null");
		this.methodCall = "write(char[10], 1, -2)";
		try {
			strWR.write(this.buf, 1, -2);
		} catch (IndexOutOfBoundsException e) {
			return;
		} catch (Exception e) {
			Assertions.fail("ROT13 method call " + this.methodCall + System.lineSeparator() + "-=- ACTUAL: exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- Expected: IndexOutOfBoundsException " + System.lineSeparator());
		}
		Assertions.fail("ROT13 method call " + this.methodCall + System.lineSeparator() + "-=- ACTUAL: no exception" + System.lineSeparator() + "-=- Expected: IndexOutOfBoundsException " + System.lineSeparator());
	}

	@DisplayName("Offset+length")
	@Test
	void testROT13OffLen() {
		Writer strWR = this.am.getROT13Writer();
		Assertions.assertNotNull(strWR, "ROT13 writer is null");
		this.methodCall = "write(char[10], 1, 10)";
		try {
			strWR.write(this.buf, 1, 10);
		} catch (IndexOutOfBoundsException e) {
			return;
		} catch (Exception e) {
			Assertions.fail("ROT13 method call " + this.methodCall + System.lineSeparator() + "-=- ACTUAL: exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- Expected: IndexOutOfBoundsException " + System.lineSeparator());
		}
		Assertions.fail("ROT13 method call " + this.methodCall + System.lineSeparator() + "-=- ACTUAL: no exception" + System.lineSeparator() + "-=- Expected: IndexOutOfBoundsException " + System.lineSeparator());
	}

	@DisplayName("Test singleton")
	@Test
	public void testSingleton() {
		String errMsg = MRTestUtils.checkSingleton("decorator.ROT13Translator");
		if (errMsg != null)
			Assertions.fail(errMsg);
	}
}
