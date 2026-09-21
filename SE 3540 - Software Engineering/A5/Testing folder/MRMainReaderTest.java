package decorator;

import java.io.IOException;
import java.io.Reader;
import java.util.Random;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvFileSource;

@DisplayName("Remote test class for MR Reader from Morse code")
class Remote_MRMainReaderTest {
	private MRMain am;

	@BeforeEach
	public void setup() {
		this.am = new MRMain();
		Assertions.assertNotNull(this.am, "Could not instantiate MRMain with default constructor.");
	}

	@Test
	@DisplayName("Initial test method with 'hello dad' string")
	public void testMorse_2() {
		String input = ".... . .-.. .-.. ---|-.. .- -..";
		String expected = "hello dad";
		Reader strMR = this.am.getMorseReader(input);
		Assertions.assertNotNull(strMR, "Morse reader is null");
		try {
			for (char expC : expected.toCharArray()) {
				int i = strMR.read();
				if (i != -1) {
					Assertions.assertEquals(expC, (char)i);
				} else {
					Assertions.fail("Morse reader unexpected stream end.");
				}
			}
			int c = strMR.read();
			Assertions.assertEquals(c, -1);
		} catch (IOException e) {
			Assertions.fail("Morse reader threw Exception " + e + " with cause: " + e.getCause());
		}
	}

	@DisplayName("Test read() from random string")
	@ParameterizedTest
	@CsvFileSource(resources = {"/morseIO.csv"})
	public void testMorseRand(String morseCode, String expected) {
		Reader strMR = this.am.getMorseReader(morseCode);
		Assertions.assertNotNull(strMR, "Morse reader is null");
		try {
			for (char expC : expected.toCharArray()) {
				int i = strMR.read();
				if (i != -1) {
					Assertions.assertEquals(expC, (char)i);
				} else {
					Assertions.fail("Morse reader unexpected stream end.");
				}
			}
			int c = strMR.read();
			Assertions.assertEquals(-1, c);
		} catch (IOException e) {
			Assertions.fail("Morse reader threw Exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- When reading from morse code: '" + morseCode + "'" + System.lineSeparator() + "-=- Expected: '" + expected + "'" + System.lineSeparator());
		}
	}

	@DisplayName("Test readcbuf, int off, int len) from random string")
	@ParameterizedTest
	@CsvFileSource(resources = {"/morseIO.csv"})
	public void testRead2Array(String morseCode, String expected) {
		Reader strMR = this.am.getMorseReader(morseCode);
		Assertions.assertNotNull(strMR, "Morse reader is null");
		int lenPar = expected.length();
		Random randg = new Random((expected.length() % 10));
		int offset = randg.nextInt(lenPar / 2);
		int len = randg.nextInt(lenPar / 2);
		char[] dest = new char[lenPar];
		char[] expectedResult = new char[lenPar];
		char[] expChr = expected.substring(0, len).toCharArray();
		for (int i = 0; i < expChr.length; i++)
			expectedResult[offset + i] = expChr[i];
		String methodCall = "read(char[], " + offset + ", " + len + ")";
		try {
			int n = strMR.read(dest, offset, len);
			Assertions.assertEquals(n, len, methodCall + " from source '" + methodCall + "'" + expected + "-=- ACTUAL return: " + System.lineSeparator() + n + "-=- EXPECTED: " + System.lineSeparator() + len);
			Assertions.assertArrayEquals(expectedResult, dest, methodCall + " from source '" + methodCall + "'" + expected + "-=- ACTUAL : '" + System.lineSeparator() + "'" + new String(dest) + "-=- EXPECTED: '" + System.lineSeparator() + "'" + new String(expChr));
		} catch (Exception e) {
			Assertions.fail("Morse reader threw Exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- When doing: " + methodCall + " from source '" + expected + "'" + System.lineSeparator() + "-=- Expected: '" + new String(expChr) + "'" + System.lineSeparator());
		}
	}

	@DisplayName("Test ready")
	@Test
	public void testReady() {
		String input = ".... . .-.. .-.. ---|-.. .- -..";
		Reader strMR = this.am.getMorseReader(input);
		Assertions.assertNotNull(strMR, "Morse reader is null");
		try {
			boolean isReady = strMR.ready();
			Assertions.assertTrue(isReady, "Reader from a string should be ready before the first read");
		} catch (Exception e) {
			Assertions.fail("Morse reader ready() threw Exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- Expected: ready() should return true for string reader before first read." + System.lineSeparator());
		}
	}

	@DisplayName("Test close")
	@Test
	public void testClose() {
		String input = ".";
		Reader strMR = this.am.getMorseReader(input);
		Assertions.assertNotNull(strMR, "Morse reader is null");
		try {
			strMR.close();
		} catch (IOException e1) {
			Assertions.fail("Morse reader close() threw Exception " + e1 + " with cause: " + e1.getCause() + System.lineSeparator() + "-=- Expected: no exception " + System.lineSeparator());
		}
		try {
			boolean isReady = strMR.ready();
			Assertions.fail("Reader from a string is ready after close() was called. ");
		} catch (IOException eio) {
			return;
		} catch (Exception e) {
			Assertions.fail("After close(), Morse reader ready() threw Exception " + e + " with cause: " + e.getCause() + System.lineSeparator() + "-=- Expected: IOException " + System.lineSeparator());
		}
	}

	@DisplayName("Test singleton")
	@Test
	public void testSingleton() {
		String errMsg = MRTestUtils.checkSingleton("decorator.MorseTranslator");
		if (errMsg != null)
			Assertions.fail(errMsg);
	}
}
