/*     */ package composite;
/*     */ 
/*     */ import java.io.InputStream;
/*     */ import java.util.ArrayDeque;
/*     */ import java.util.Deque;
/*     */ import java.util.List;
/*     */ import java.util.Map;
/*     */ import java.util.Optional;
/*     */ import java.util.Random;
/*     */ import org.junit.jupiter.api.Assertions;
/*     */ import org.junit.jupiter.params.ParameterizedTest;
/*     */ import org.junit.jupiter.params.provider.MethodSource;
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ class CompositeTest
/*     */ {
/*     */   ItemManager im;
/*  24 */   static final String ls = System.lineSeparator();
/*     */   
/*     */   static final double MAXPRICE = 1000.0D;
/*     */ 
/*     */   
/*     */   @ParameterizedTest
/*     */   @MethodSource({"composite.ItemTestUtils#genNamePrice"})
/*     */   public void testGetPrice(InputStream instr, List<String> items, List<Optional<Double>> prices, String allIn) {
/*  32 */     this.im = new ItemManager();
/*     */     try {
/*  34 */       this.im.readXml(instr);
/*  35 */     } catch (Exception e) {
/*  36 */       Assertions.fail("Unexpected readXml exception: " + e.getMessage() + ls + "Input: " + ls + allIn);
/*     */     } 
/*  38 */     for (int i = 0; i < items.size(); i++) {
/*  39 */       Assertions.assertEquals(prices.get(i), this.im.getPrice(items.get(i)), "Wrong price for item " + (String)items.get(i) + ls + "Input:" + ls + allIn);
/*     */     }
/*     */   }
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   
/*     */   @ParameterizedTest
/*     */   @MethodSource({"composite.ItemTestUtils#genRemoveArgs"})
/*     */   public void testRemove(InputStream instr, Map<String, String> parentOf, Map<String, Optional<Double>> priceOf, String allIn) {
/*  54 */     Object[] items = parentOf.keySet().toArray();
/*  55 */     StringBuilder prevCalls = new StringBuilder();
/*     */     
/*  57 */     this.im = new ItemManager();
/*     */     try {
/*  59 */       this.im.readXml(instr);
/*  60 */     } catch (Exception e) {
/*  61 */       Assertions.fail("Unexpected readXml exception: " + e.getMessage() + ls + "Input: " + ls + allIn);
/*     */     } 
/*     */ 
/*     */     
/*  65 */     Random rand = new Random();
/*  66 */     int testCount = 1000;
/*  67 */     int nrOfSuccessfullRemoves = items.length - 3;
/*     */ 
/*     */     
/*  70 */     String item = (String)items[rand.nextInt(items.length)];
/*  71 */     Deque<String> parentStack = getAllParents(item, parentOf);
/*  72 */     String rootName = parentStack.peek();
/*     */     
/*  74 */     while (nrOfSuccessfullRemoves > 0 && testCount > 0) {
/*     */       
/*  76 */       testCount--;
/*     */       
/*  78 */       item = (String)items[rand.nextInt(items.length)];
/*     */       
/*  80 */       String metCall = "removeItem(" + item + ")";
/*     */       
/*  82 */       String context = "Initial input: " + ls + allIn + ls + "Previous method calls: " + ls + prevCalls.toString();
/*     */ 
/*     */ 
/*     */ 
/*     */       
/*  87 */       parentStack = getAllParents(item, parentOf);
/*  88 */       boolean itemPresentAndNotRoot = (parentStack.size() > 1 && rootName.equals(parentStack.peek()));
/*     */       
/*  90 */       context = "Initial input: " + ls + allIn + ls + "Previous method calls: " + ls + prevCalls.toString();
/*  91 */       boolean actualRemoved = this.im.removeItem(item);
/*     */       
/*  93 */       Assertions.assertEquals(Boolean.valueOf(itemPresentAndNotRoot), Boolean.valueOf(actualRemoved), metCall + " should return " + metCall + ". " + itemPresentAndNotRoot + ls);
/*     */       
/*  95 */       if (actualRemoved) {
/*  96 */         String parentOfRemoved = parentOf.remove(item);
/*  97 */         double priceOfRemoved = ((Double)((Optional<Double>)priceOf.get(item)).get()).doubleValue();
/*  98 */         while (parentOfRemoved != null) {
/*  99 */           double parentPrice = ((Double)this.im.getPrice(parentOfRemoved).get()).doubleValue();
/* 100 */           double prevPrice = ((Double)((Optional<Double>)priceOf.get(parentOfRemoved)).get()).doubleValue();
/* 101 */           Assertions.assertEquals(prevPrice - priceOfRemoved, parentPrice, "In " + metCall + ls + "Price of item " + parentOfRemoved + " should be lower by " + priceOfRemoved + ls + context);
/* 102 */           priceOf.put(parentOfRemoved, Optional.of(Double.valueOf(prevPrice - priceOfRemoved)));
/* 103 */           parentOfRemoved = parentOf.get(parentOfRemoved);
/*     */         } 
/* 105 */         nrOfSuccessfullRemoves--;
/*     */       } 
/* 107 */       prevCalls.append(metCall + ": " + metCall + actualRemoved);
/*     */     } 
/*     */   }
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   
/*     */   @ParameterizedTest
/*     */   @MethodSource({"composite.ItemTestUtils#genMoveArgs"})
/*     */   public void testChangePrice(InputStream instr, Map<String, String> parentOf, Map<String, String> parentOfAtomic, Map<String, String> parentOfList, Map<String, Optional<Double>> priceOf, String allIn) {
/* 121 */     Object[] items = parentOf.keySet().toArray();
/* 122 */     StringBuilder prevCalls = new StringBuilder();
/*     */     
/* 124 */     this.im = new ItemManager();
/*     */     try {
/* 126 */       this.im.readXml(instr);
/* 127 */     } catch (Exception e) {
/* 128 */       Assertions.fail("Unexpected readXml exception: " + e.getMessage() + ls + "Input: " + ls + allIn);
/*     */     } 
/*     */     
/* 131 */     Random rand = new Random();
/* 132 */     int testCount = 40;
/*     */     
/* 134 */     for (int i = 0; i < testCount; i++) {
/*     */       
/* 136 */       double changedP = 1000.0D * rand.nextDouble();
/* 137 */       String item = (String)items[rand.nextInt(items.length)];
/* 138 */       Optional<Double> prevPrice = this.im.getPrice(item);
/* 139 */       double priceDiff = changedP - ((Double)prevPrice.get()).doubleValue();
/*     */       
/* 141 */       boolean changed = this.im.changePrice(item, changedP);
/* 142 */       String metCall = "changePrice(" + item + ", " + changedP + ")";
/* 143 */       if (parentOfList.containsKey(item) || item.equals("root")) {
/* 144 */         Assertions.assertFalse(changed, "Method call: " + metCall + ls + "Input: " + ls + allIn);
/*     */       } else {
/*     */         
/* 147 */         if (parentOfAtomic.containsKey(item) && changedP > 0.0D) {
/* 148 */           Assertions.assertTrue(changed, "Method call: " + metCall + ls + "Input: " + ls + allIn);
/* 149 */           Deque<String> parentsOfChanged = getAllParents(item, parentOfList);
/* 150 */           while (parentsOfChanged.peek() != null) {
/* 151 */             String parent = parentsOfChanged.pop();
/* 152 */             priceOf.put(parent, Optional.of(Double.valueOf(((Double)((Optional<Double>)priceOf.get(parent)).get()).doubleValue() + priceDiff)));
/* 153 */             double parPrice = ((Double)this.im.getPrice(parent).get()).doubleValue();
/* 154 */             Assertions.assertEquals(((Double)((Optional<Double>)priceOf.get(parent)).get()).doubleValue(), parPrice, 1.0E-9D, "Price of " + parent + " did not change after " + metCall + ls + "Previous method calls: " + ls + prevCalls + ls + "Input " + ls + allIn);
/*     */           } 
/*     */         } 
/*     */         
/* 158 */         prevCalls.append(metCall + "\n");
/*     */       } 
/*     */     } 
/*     */   } @ParameterizedTest
/*     */   @MethodSource({"composite.ItemTestUtils#genreadXMLArgs"})
/*     */   public void testReadXML(InputStream instr, String allIn) {
/* 164 */     this.im = new ItemManager();
/*     */     try {
/* 166 */       this.im.readXml(instr);
/* 167 */       Assertions.fail("readXML should throw exception on input " + ls + allIn);
/* 168 */     } catch (Exception exception) {}
/*     */   }
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   
/*     */   private Deque<String> getAllParents(String directParent, Map<String, String> parentOfList) {
/* 178 */     Deque<String> parents = new ArrayDeque<>();
/* 179 */     parents.push(directParent);
/* 180 */     String p = parentOfList.get(directParent);
/* 181 */     while (p != null) {
/* 182 */       parents.push(p);
/* 183 */       p = parentOfList.get(p);
/*     */     } 
/* 185 */     return parents;
/*     */   }
/*     */ }


/* Location:              C:\Users\layne\Downloads\Composite_Test-0.0.1-20221111.074659-3-tests.jar!\composite\CompositeTest.class
 * Java compiler version: 11 (55.0)
 * JD-Core Version:       1.1.3
 */