/*     */ package composite;
/*     */ 
/*     */ import java.io.BufferedInputStream;
/*     */ import java.io.BufferedReader;
/*     */ import java.io.FileInputStream;
/*     */ import java.io.FileNotFoundException;
/*     */ import java.io.FileReader;
/*     */ import java.io.IOException;
/*     */ import java.io.InputStream;
/*     */ import java.util.ArrayList;
/*     */ import java.util.HashMap;
/*     */ import java.util.List;
/*     */ import java.util.Map;
/*     */ import java.util.Optional;
/*     */ import org.junit.jupiter.params.provider.Arguments;
/*     */ 
/*     */ public class ItemTestUtils
/*     */ {
/*     */   static final int nrInputs = 2;
/*     */   static final int nrIncIns = 3;
/*  21 */   static final String[] inputFiles = new String[] { "input1.xml", "input2.xml" };
/*  22 */   static final String[] incorrectFiles = new String[] { "input3.xml", "input4.xml", "input5.xml" };
/*  23 */   private static List<String>[] names = (List<String>[])new ArrayList[2];
/*  24 */   private static List<Optional<Double>>[] prices = (List<Optional<Double>>[])new ArrayList[2];
/*  25 */   private static StringBuilder[] allInput = new StringBuilder[2];
/*     */   private static BufferedReader br;
/*  27 */   private static Map<String, String>[] parentOfAtomic = (Map<String, String>[])new HashMap[2];
/*  28 */   private static Map<String, String>[] parentOfList = (Map<String, String>[])new HashMap[2];
/*  29 */   private static Map<String, Optional<Double>>[] priceOf = (Map<String, Optional<Double>>[])new HashMap[2];
/*  30 */   private static Map<String, String>[] parentOf = (Map<String, String>[])new HashMap[2];
/*     */   
/*     */   private static void reset() {
/*  33 */     for (int i = 0; i < 2; i++) {
/*  34 */       names[i] = new ArrayList<>();
/*  35 */       prices[i] = new ArrayList<>();
/*  36 */       allInput[i] = new StringBuilder();
/*  37 */       parentOfAtomic[i] = new HashMap<>();
/*  38 */       parentOfList[i] = new HashMap<>();
/*  39 */       parentOf[i] = new HashMap<>();
/*  40 */       priceOf[i] = new HashMap<>();
/*     */     } 
/*     */   }
/*     */   
/*     */   private static void fillInput(String fname, StringBuilder inb) {
/*     */     try {
/*  46 */       br = new BufferedReader(new FileReader(fname));
/*  47 */       String ln = br.readLine();
/*  48 */       while (ln != null) {
/*  49 */         inb.append(ln + "\n");
/*  50 */         ln = br.readLine();
/*     */       } 
/*  52 */       br.close();
/*  53 */     } catch (FileNotFoundException e) {
/*     */       
/*  55 */       e.printStackTrace();
/*  56 */     } catch (IOException e) {
/*     */       
/*  58 */       e.printStackTrace();
/*     */     } 
/*     */   }
/*     */   
/*     */   private static void readFieldsFromFile(int rank) {
/*  63 */     fillInput(inputFiles[rank], allInput[rank]);
/*     */     try {
/*  65 */       br = new BufferedReader(new FileReader(inputFiles[rank]));
/*  66 */       String ln = br.readLine();
/*  67 */       if (ln.startsWith("<list"))
/*  68 */         readList(ln, rank); 
/*  69 */       br.close();
/*  70 */     } catch (FileNotFoundException e) {
/*     */       
/*  72 */       e.printStackTrace();
/*  73 */     } catch (IOException e) {
/*     */       
/*  75 */       e.printStackTrace();
/*     */     } 
/*     */   }
/*     */   
/*     */   private static double readList(String ln, int rank) {
/*  80 */     double listPrice = 0.0D;
/*     */     
/*  82 */     String delims = "[<>\\s=\\\"]+";
/*  83 */     String[] elems = ln.split(delims);
/*  84 */     String listName = elems[3];
/*     */     
/*     */     try {
/*  87 */       ln = br.readLine();
/*  88 */       while (ln != null) {
/*  89 */         elems = ln.split(delims);
/*  90 */         if (elems.length > 1) {
/*  91 */           if (elems[1].equals("list")) {
/*  92 */             listPrice += readList(ln, rank);
/*  93 */             parentOfList[rank].put(elems[3], listName);
/*  94 */             parentOf[rank].put(elems[3], listName);
/*     */           } else {
/*  96 */             if (elems[1].equals("/list")) {
/*  97 */               names[rank].add(listName);
/*  98 */               prices[rank].add(Optional.of(Double.valueOf(listPrice)));
/*  99 */               priceOf[rank].put(listName, Optional.of(Double.valueOf(listPrice)));
/* 100 */               return listPrice;
/*     */             } 
/*     */             
/* 103 */             if (elems.length > 5) {
/* 104 */               String nameI = elems[3];
/* 105 */               names[rank].add(nameI);
/* 106 */               double ip = Double.parseDouble(elems[5]);
/* 107 */               prices[rank].add(Optional.of(Double.valueOf(ip)));
/* 108 */               listPrice += ip;
/* 109 */               parentOfAtomic[rank].put(nameI, listName);
/* 110 */               parentOf[rank].put(nameI, listName);
/* 111 */               priceOf[rank].put(nameI, Optional.of(Double.valueOf(ip)));
/*     */             } else {
/*     */               
/* 114 */               System.out.println("unexpected length of input at line: " + ln);
/*     */             } 
/*     */           } 
/*     */         }
/* 118 */         ln = br.readLine();
/*     */       } 
/* 120 */     } catch (IOException e) {
/* 121 */       e.printStackTrace();
/*     */     } 
/* 123 */     throw new IllegalArgumentException("readList reached the end !");
/*     */   }
/*     */   
/*     */   public static Arguments[] genNamePrice() {
/* 127 */     reset();
/* 128 */     Arguments[] args = new Arguments[2];
/* 129 */     for (int i = 0; i < 2; i++) {
/* 130 */       readFieldsFromFile(i);
/*     */       try {
/* 132 */         InputStream ins = new BufferedInputStream(new FileInputStream(inputFiles[i]));
/* 133 */         names[i].add("Unknown" + i);
/* 134 */         prices[i].add(Optional.empty());
/* 135 */         args[i] = Arguments.of(new Object[] { ins, names[i], prices[i], allInput[i].toString() });
/* 136 */       } catch (FileNotFoundException e) {
/*     */         
/* 138 */         e.printStackTrace();
/*     */         break;
/*     */       } 
/*     */     } 
/* 142 */     return args;
/*     */   }
/*     */   
/*     */   public static Arguments[] genRemoveArgs() {
/* 146 */     reset();
/* 147 */     Arguments[] args = new Arguments[2];
/* 148 */     for (int i = 0; i < 2; i++) {
/* 149 */       readFieldsFromFile(i);
/*     */       try {
/* 151 */         InputStream ins = new BufferedInputStream(new FileInputStream(inputFiles[i]));
/* 152 */         args[i] = Arguments.of(new Object[] { ins, parentOf[i], priceOf[i], allInput[i].toString() });
/* 153 */       } catch (FileNotFoundException e) {
/*     */         
/* 155 */         e.printStackTrace();
/*     */         break;
/*     */       } 
/*     */     } 
/* 159 */     return args;
/*     */   }
/*     */   
/*     */   public static Arguments[] genMoveArgs() {
/* 163 */     reset();
/* 164 */     Arguments[] args = new Arguments[2];
/* 165 */     for (int i = 0; i < 2; i++) {
/* 166 */       readFieldsFromFile(i);
/*     */       try {
/* 168 */         InputStream ins = new BufferedInputStream(new FileInputStream(inputFiles[i]));
/* 169 */         args[i] = Arguments.of(new Object[] { ins, parentOf[i], parentOfAtomic[i], parentOfList[i], priceOf[i], allInput[i].toString() });
/* 170 */       } catch (FileNotFoundException e) {
/*     */         
/* 172 */         e.printStackTrace();
/*     */         break;
/*     */       } 
/*     */     } 
/* 176 */     return args;
/*     */   }
/*     */   
/*     */   public static Arguments[] genreadXMLArgs() {
/* 180 */     Arguments[] args = new Arguments[3];
/* 181 */     for (int i = 0; i < 3; i++) {
/* 182 */       StringBuilder incb = new StringBuilder();
/* 183 */       fillInput(incorrectFiles[i], incb);
/*     */       try {
/* 185 */         InputStream ins = new BufferedInputStream(new FileInputStream(incorrectFiles[i]));
/* 186 */         args[i] = Arguments.of(new Object[] { ins, incb.toString() });
/* 187 */       } catch (FileNotFoundException e) {
/*     */         
/* 189 */         e.printStackTrace();
/*     */         break;
/*     */       } 
/*     */     } 
/* 193 */     return args;
/*     */   }
/*     */ }


/* Location:              C:\Users\layne\Downloads\Composite_Test-0.0.1-20221111.074659-3-tests.jar!\composite\ItemTestUtils.class
 * Java compiler version: 11 (55.0)
 * JD-Core Version:       1.1.3
 */