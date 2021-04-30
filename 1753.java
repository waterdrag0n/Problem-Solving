import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main{
    static final int INF = 2000000;
    static int n;
    static ArrayList<Edge> map[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String tmp[] = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        map = new ArrayList[n+1];
        int start = Integer.parseInt(br.readLine());
        for(int i=1;i<n+1;i++)
            map[i] = new ArrayList<>();
        int v = Integer.parseInt(tmp[1]);
        for(int i=0;i<v;i++){
            tmp = br.readLine().split(" ");
            int from = Integer.parseInt(tmp[0]);
            int to = Integer.parseInt(tmp[1]);
            int weight= Integer.parseInt(tmp[2]);
            map[from].add(new Edge(to, weight));
        }
        dijk(start);
        bw.flush();
        bw.close();
    }
    static void dijk(int start){
        int[] dist = new int[n+1];

        Arrays.fill(dist, INF);
        dist[start] = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(start, 0));
        while(!pq.isEmpty()){
            int cur = pq.peek().end;
            int dis = pq.peek().weight;
            pq.poll();
            if(dist[cur]<dis) continue;
            for(int i=0;map[cur]!=null && i<map[cur].size();i++){
                int next= map[cur].get(i).end;
                int nextDist = dis+map[cur].get(i).weight;
                if(nextDist<dist[next]){
                    dist[next] = nextDist;
                    pq.add(new Edge(next, nextDist));
                }
            }
        }
        for(int i=1;i<=n;i++)
            System.out.println(dist[i]==INF?"INF":dist[i]);
    }
}
class Edge implements Comparable<Edge>{
    int end;
    int weight;
    Edge(int to, int value){
        this.end = to;
        this.weight = value;
    }
    @Override
    public int compareTo(Edge target) {
        return this.weight - target.weight;
    }
}