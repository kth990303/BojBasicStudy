package Ex1388;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		char graph[][] = new char[N][M];
		
		for(int i=0; i<N; i++)
		{
			String str = sc.next();
			char[] arr = str.toCharArray();
			for(int j=0; j<M; j++)
			{
				graph[i][j] = arr[j];
			}
		}
		
		int cnt1 = 0;
		for(int i=0; i<N; i++)
		{
			int cnt = 0;
			for(int j=0; j<M-1; j++)
			{
				if(graph[i][j] == '-' && graph[i][j+1] == '-')
					cnt++;
			}
			
			for(int j=0; j<M; j++)
			{
				if(graph[i][j] == '|')
					cnt++;
			}
			cnt1 += (M-cnt);
			
		}
		
		int cnt2 = 0;
		for(int j=0; j<M; j++)
		{
			int cnt = 0;
			for(int i=0; i<N-1; i++)
			{
				if(graph[i][j] == '|' && graph[i+1][j] == '|')
					cnt++;
			}
			
			for(int i=0; i<N; i++)
			{
				if(graph[i][j] == '-')
					cnt++;
			}
			cnt2 += (N-cnt);
		}
		
		System.out.println(cnt1+cnt2);
	}

}
