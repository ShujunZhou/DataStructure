package com.zsj.testtree;

public class BulidBinaryTree {
	public static BinaryTree creat(){
		TreeNode a, b, c, d, e, f, g;
		
		f = new TreeNode("F");
		g = new TreeNode("G");
		d = new TreeNode("D");
		c = new TreeNode("C");
		
		e = new TreeNode("E", f, g);
		b = new TreeNode("B", d, e);
		a = new TreeNode("A", b, c);
		
		return new BinaryTree(a);
	} 
}
