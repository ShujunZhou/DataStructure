package com.zsj.tree;

/*
 * �ڵ���
 * */

class TreeNode {
	private Object nodeValue;
	private TreeNode left, right;
	
	//�սڵ�
	public TreeNode(){
		this(null, null, null);
	}
	//Ҷ��
	public TreeNode(Object item){
		this(item, null, null);
	}
	//�����ڵ�
	public TreeNode(Object item, TreeNode left, TreeNode right){
		nodeValue = item;
		this.left = left;
		this.right = right;
	}
	
	//�ж��Ƿ�ΪҶ��
	public boolean isEmpty(TreeNode node){
		if (node.left == null && node.right == null){
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
			result += "������" + left.toString();
		}
		if (right != null){
			result += "������" + right.toString();
		}
		
		result += ")";
		return result;
	}
}
