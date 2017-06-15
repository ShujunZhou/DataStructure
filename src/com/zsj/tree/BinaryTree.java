package com.zsj.tree;

/*
 * ���������
 * */

class BinaryTree {
	protected TreeNode root;//����һ���ڵ�����Ա
	
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
