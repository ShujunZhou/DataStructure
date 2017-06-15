package com.zsj.testtree;

/*
 * 创建二叉树
 * */

public class BinaryTree {
	private TreeNode root;
	
	public BinaryTree(){
		this.root = null;
	}
	
	public BinaryTree(TreeNode root){
		this.root = root;
	}
	
	public TreeNode getNode(){
		return root;
	}
	
	public boolean isEmpty(){
		if (this.root == null)
			return true;
		
		return false;
	}
	
	public String toString(){
		return root.toString();
	}
}
