
import java.io.*;
import java.util.*;
import java.math.*;
public class n {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		BigInteger ans,i,n;
		while(cin.hasNext())
		{
			n=cin.nextBigInteger();
			i=ans=BigInteger.ONE;
			while(i.compareTo(n)<=0)
			{
				ans=ans.multiply(i);
				i=i.add(BigInteger.ONE);
			}
			System.out.println(ans);
		}
	}
}
