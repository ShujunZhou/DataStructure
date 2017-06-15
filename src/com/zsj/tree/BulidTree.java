package com.zsj.tree;

/*
 * ¹¹Ôì¶þ²æÊ÷
 * */
class BulidTree {
	public static BinaryTree create() {
		TreeNode a, b, c, d, e, f, g;

		//x创建叶子
		f = new TreeNode("F");
		g = new TreeNode("G");
		d = new TreeNode("D");
		c = new TreeNode("C");
		//创建根节点
		e = new TreeNode("E", f, g);
		b = new TreeNode("B", d, e);
		a = new TreeNode("A", b, c);
		
		return new BinaryTree(a);
	}
}
