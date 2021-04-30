import java.util.*;

public class Main{
    static Stack<Integer> stack;
    static boolean visited[];
    static int v;
    static ArrayList<Integer> board[];
    static ArrayList<Integer> rev[];
    static List<List<Integer>> list = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        v = sc.nextInt();
        int e = sc.nextInt();

        board = new ArrayList[v+1];
        rev = new ArrayList[v+1];

        // initializing
        for (int i = 1; i < v+1; i++) {
            board[i] = new ArrayList<>();
            rev[i] = new ArrayList<>();
        }

        for(int i=0;i<e;i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            board[from].add(to);
            rev[to].add(from);
        }
        stack = new Stack<>();
        visited = new boolean[v+1];
        for(int i=1;i<v+1;i++){
            if(visited[i]) continue;
            DFS(i);
        }

        visited = new boolean[v+1];
        while(!stack.empty()){
            int cur = stack.pop();
            if(visited[cur]) continue;
            List<Integer> tmpList = new ArrayList<>();
            dfsRev(cur, tmpList);
            tmpList.sort(null);
            list.add(tmpList);
        }
        list.sort((l1, l2) -> l1.get(0).compareTo(l2.get(0)));
        showList();
    }

    static void showList(){
        System.out.println(list.size());
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.get(i).size();j++){
                System.out.print(list.get(i).get(j)+" ");
            }
            System.out.println(-1);
        }
    }

    static void dfsRev(int start, List<Integer> tmpList){
        visited[start] = true;
        tmpList.add(start);
        for(int i=0;i<rev[start].size();i++){
            if(visited[rev[start].get(i)] || rev[start].get(i)==start) {
                continue;
            }
            dfsRev(rev[start].get(i), tmpList);
        }
    }

    static void DFS(int start){
        visited[start] = true;
        for(int i=0;i<board[start].size();i++){
            if(visited[board[start].get(i)] || board[start].get(i)==start) {
                continue;
            }
            DFS(board[start].get(i));
        }
        stack.push(start);
    }
}