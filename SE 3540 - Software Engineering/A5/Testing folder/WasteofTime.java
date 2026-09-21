package decorator;

import java.io.*;

public interface MREncoding {
	/**
	 *
	 * @param file2read : refers to a text file to be read, with Morse code of letters [a-z] separated by space
	 * @return a reader that enables reading the letters [a-z] as encoded in the file. This must use a Translator implementation!
	 */
	public Reader getMorseReader(File file2read) throws FileNotFoundException{
		Reader fileReaderTest = new FileReader(file2read);
		fileReaderTest.ready();
		//system.out.println("File reader ready status: " fileReader.ready());


		fileReaderTest.close();
		return fileReaderTest;
	}

	/**
	 * Similar with above, but the source with Morse code is the provided string
	 * @param string2read
	 * @return
	 */
	public Reader getMorseReader(String string2read){
		Reader stringReader = new FileReader(string2read);
		stringReader.ready();
		//system.out.println("File reader ready status: " stringReader.ready());

		stringReader.close();
		//return
	}

	/**
	 *
	 * @param file2Write : refers to a text file to be written
	 * @return a writer that writes in ROT13 code. This must use a Translator implementation!
	 */
	public Writer getROT13Writer(File file2Write){
		Writer fileWriterReturn;

		return fileWriterReturn;
	}

	/**
	 * Similar to above, but with output going to a String.
	 * @return a writer that writes into an internal String, returned by its toString method.
	 */
	public Writer getROT13Writer(){
		Writer stringWriterReturn;

		return stringWriterReturn.toString();
	}

}
