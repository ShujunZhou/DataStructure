package graph;

/**
 * Created by shu on 2017/7/16.
 * 图测试类
 */
public class Test {
    public static void main(String[] args) {
        //顶点集合
        char[] mVexs = {'A', 'B', 'C', 'D', 'E', 'F'};
        //图
        char[][] graph = {
                {'A', 'B'},
                {'A', 'C'},
                {'A', 'D'},
                {'B', 'C'},
                {'B', 'D'},
                {'C', 'D'},
                {'D', 'E'},
                {'E', 'F'}
        };
        //无向图的邻接矩阵表示
        int[][] mMatrix = MatrixUDG.createMatrix(mVexs, graph);
        for (int i = 0; i < mMatrix.length; ++i) {
            for (int j = 0; j < mMatrix[0].length; ++j) {
                System.out.print(mMatrix[i][j] + " ");
            }
            System.out.println();
        }
        MatrixUDG.DFS();
        System.out.println("\n广度优先遍历(BFS)的结果为");
        MatrixUDG.BFS();
    }
}
