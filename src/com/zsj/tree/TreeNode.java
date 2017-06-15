package com.zsj.tree;

/*
 * 节点类
 * */

class TreeNode {
	private Object nodeValue;
	private TreeNode left, right;
	
	//空节点
	public TreeNode(){
		this(null, null, null);
	}
	//叶子
	public TreeNode(Object item){
		this(item, null, null);
	}
	//正常节点
	public TreeNode(Object item, TreeNode left, TreeNode right){
		nodeValue = item;
		this.left = left;
		this.right = right;
	}
	
	//判断是否为叶子
	public boolean isEmpty(TreeNode node){
		if (node.left == null && node.right == null){
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
			result += "左子树" + left.toString();
		}
		if (right != null){
			result += "右子树" + right.toString();
		}
		
		result += ")";
		return result;
	}
}
