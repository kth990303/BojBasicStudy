package Ex17291;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int[] a = new int[30];
		
		a[1]=1; a[4] = -1;
		
		// 새로 생성된 개체 수는 그 전년도의 개체 수
		for(int i=2; i<=N; i++)
		{
			int minus = a[i-1];
			a[i] += a[i-1]*2;
			
			if(i%2==1)
				a[i+3] = a[i+3] - minus;
			else
				a[i+4] = a[i+4] - minus;
		}
		
		System.out.println(a[N]);
		
	
		
	}
}
