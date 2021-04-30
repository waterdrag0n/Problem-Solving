import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main{
    static int g;
    static ArrayList<Integer> list[];
    static int[] link;
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        list = new ArrayList[n+1];
        link = new int[n+1];
        for(int i=1;i<=n;i++)
            list[i] = new ArrayList<>();
        for(int i=0;i<m;i++){
            tmp = br.readLine().split(" ");
            int from = Integer.parseInt(tmp[0]);
            int to = Integer.parseInt(tmp[1]);
            list[from].add(to);
        }
        makeLink();
        topologicalOrder();

    }

    static void topologicalOrder() {
        Queue<Integer> q = new LinkedList();
        ArrayList<Integer> result = new ArrayList<>();
        for(int i=1;i<=n;i++){
            if(link[i]==0)
                q.offer(i);
        }
        for(int k=1;k<=n;k++){
            int cur = q.poll();
            result.add(cur);
            for(int i=0;i<list[cur].size();i++){
                link[list[cur].get(i)]--;
                if(link[list[cur].get(i)]==0)
                    q.offer(list[cur].get(i));

            }
        }
        for(int i=0;i<result.size()-1;i++)
            System.out.print(result.get(i)+" ");
        System.out.println(result.get(result.size()-1));

    }

    static void makeLink(){

        for(int i=1;i<=n;i++){
            for(int j=0;j<list[i].size();j++){
                link[list[i].get(j)]++;
            }
        }
    }
}