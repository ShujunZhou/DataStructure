package com.zsj.tree;

/*
 * 构造二叉树
 * */

class BinaryTree {
	protected TreeNode root;//定义一个节点对象成员
	
	public BinaryTree(){
		root = null;
	}
	
	public BinaryTree(TreeNode root){
		this.root = root;
	}
	
	public boolean isEmpty(){
		return this.root == null;
	}
	
	public TreeNode getRoot(){
		return root;
	}
	
	public String toString(){
		return root.toString();
	}
}
