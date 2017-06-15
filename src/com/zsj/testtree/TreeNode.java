package com.zsj.testtree;

/*
 * 创建节点
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
	//判断当前节点是否为叶子
	public boolean isEmpty(){
		if (this.left == null && this.left == null){
			return true;
		}
		return false;
	}
	//重写toString方法
	public String toString(){
		if (nodeValue == null){
			return null;
		}
		
		String result = "(节点" + nodeValue.toString();
		
		if (left != null){
			result += "左节点" + left.toString();
		}
		if (right != null){
			result += "右节点" + right.toString();
		}
		
		result += ")";
		return result;
	}
}
