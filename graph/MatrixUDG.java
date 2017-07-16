package graph;

/**
 * Created by shu on 2017/7/15.
 * 邻接矩阵表示的"无向图(Matrix Undirected Graph)
 */
public class MatrixUDG {
    //顶点集合
    private static char[] mVexs;
    //邻接矩阵
    private static int[][] mMatrix;

    /*
    根据给定数据构造邻接矩阵
     */
    public static int[][] createMatrix(char[] vexs, char[][] edges) {
        int vlen = vexs.length;
        int elen = edges.length;

        mVexs = new char[vlen];
        mMatrix = new int[vlen][vlen];

        for (int i = 0; i < vlen; ++i) {
            mVexs[i] = vexs[i];
        }

        for (int i = 0; i < elen; ++i) {
            int p1 = getPosition(edges[i][0]);
            int p2 = getPosition(edges[i][1]);

            mMatrix[p1][p2] = 1;
            mMatrix[p2][p1] = 1;
        }

        return mMatrix;
    }

    //返回给定点在顶点数组中的位置
    private static int getPosition(char ch) {
        for (int i = 0; i < mVexs.length; ++i) {
            if (ch == mVexs[i]) {
                return i;
            }
        }
        return -1;
    }

    //DFS(深度优先遍历)
    public static void DFS() {
        //定义访问节点标识符
        boolean[] visited = new boolean[mVexs.length];
        //初始化
        for (int i = 0; i < mVexs.length; ++i) {
            visited[0] = false;
        }

        System.out.println("深度遍历(DFS)的结果为");
        for (int i = 0; i < mVexs.length; ++i) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }

    private static void DFS(int v, boolean[] visited) {
        if (v < 0 || v >= mVexs.length) {
            return;
        }

        visited[v] = true;
        System.out.print(mVexs[v]);

        //注意这里的判断条件为w >= 0
        for (int w = firstPosition(v); w >= 0; w = nextPosition(v, w)) {
            if (!visited[w]) {
                DFS(w, visited);
            }
        }
    }

    private static int firstPosition(int v) {
        for (int i = 0; i < mVexs.length; ++i) {
            //根据邻接矩阵的特点计算第一个1的位置
            if (mMatrix[v][i] == 1) {
                return i;
            }
        }

        return -1;
    }

    //计算相对于相邻节点v, w的下一个节点，(下一个1的位置)
    //v确定了行，w确定列的起始位置
    private static int nextPosition(int v, int w) {
        for (int i = w + 1; i < mVexs.length; ++i) {
            if (mMatrix[v][i] == 1) {
                return i;
            }
        }

        return -1;
    }


    //广度优先算法
    public static void BFS() {
        //队列头
        int head = 0;
        //队列尾
        int rear = 0;

        //访问标记数组
        boolean[] visited = new boolean[mVexs.length];
        //初始化数组
        for (int i = 0; i < visited.length; ++i) {
            visited[i] = false;
        }

        //构建队列
        int[] queue = new int[visited.length];

        for (int i = 0; i < mVexs.length; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                System.out.print(mVexs[i]);
                queue[rear++] = i; //入队列
            }

            while (head != rear) {
                int j = queue[head++]; //出队列
                for (int k = firstPosition(j); k >= 0; k = nextPosition(j, k)) {
                    if (!visited[k]) {
                        visited[k] = true;
                        System.out.print(mVexs[k]);
                        queue[rear++] = k;
                    }
                }
            }
        }
    }
}
