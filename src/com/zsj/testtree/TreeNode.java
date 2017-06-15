package com.zsj.testtree;

/*
 * �����ڵ�
 * */

class TreeNode {
	private Object nodeValue;
	private TreeNode left, right;
	
	public TreeNode(){
		this(null, null, null);
	}
	
	public TreeNode(Object item){
		nodeValue = item;
	}
	
	public TreeNode(Object item, TreeNode left, TreeNode right){
		nodeValue = item;
		this.left = left;
		this.right = right;
	}
	//�жϵ�ǰ�ڵ��Ƿ�ΪҶ��
	public boolean isEmpty(){
		if (this.left == null && this.left == null){
			return true;
		}
		return false;
	}
	//��дtoString����
	public String toString(){
		if (nodeValue == null){
			return null;
		}
		
		String result = "(�ڵ�" + nodeValue.toString();
		
		if (left != null){
			result += "��ڵ�" + left.toString();
		}
		if (right != null){
			result += "�ҽڵ�" + right.toString();
		}
		
		result += ")";
		return result;
	}
}
