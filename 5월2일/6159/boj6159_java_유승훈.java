package Ex6159;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int S = sc.nextInt();
		
		int[] size = new int[N];
		
		for(int i=0; i<N; i++)
		{
			size[i] = sc.nextInt();
		}
		
		Arrays.sort(size);
		
		int sum = 0;
		for(int i=0; i<N-1; i++)
		{
			for(int j=i+1; j<N; j++)
			{
				if(size[i]+size[j]<=S)
					sum++;
			}
		}
		System.out.println(sum);

	}

}
