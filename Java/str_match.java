import java.util.Scanner;
class str_match {
    public static void match(char[] T, char[] P) {
        int n = T.length;
        int m = P.length;
        char M[] = new char[100];
        int i=0;
	    int j=0;
	    int k=0;
	    while(i < n) {
            j=0;                   // 1. Comparing the first element of the pattern with each element of the Text. 
            k=0;                              
            while(T[i] == P[j] ) {  
                M[k] = P[j];       // 2. If the both the char match then character is stored into new char[] M. 
                i++;               // 3. If the characters continue to match 
                j++;               // while traversing through Text and Pattern goto step 2.
                k++;             
                if(k==m) {         // 4. On each iteration, size of M[] and Pattern is compared, if equal 
                    System.out.println("Pattern found at "+((i-m)+1)); // pattern found at i-m.
                    i--;           
                    k=0;	   // 5. Clear the buffer array.
                }
                if(j>(m-1) || i>(n-1))  // ** To avoid ArrayIndexOutOfBounds Exception in the entry control.
                    break;
            }
            if(i<n && T[i] == P[0])    // ** For handling one error input case
                continue;
            i++;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String Text = sc.nextLine();
        String Pattern = sc.nextLine();
        char[] T = Text.toCharArray();
        char[] P = Pattern.toCharArray();
        long t1 = System.nanoTime();
        match(T,P);
        long t2 = System.nanoTime();    
        long millis = t2 - t1;
        System.out.println("That took : " +millis+" ns");
    }
}
