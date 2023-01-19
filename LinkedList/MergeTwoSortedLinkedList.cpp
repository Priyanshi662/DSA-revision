if(list1->val>list2->val)
  {
      Node* current=list1;
      list1=list2;
      list2=current;
  }
  //ensuring list1 contains smaller value than list2
  Node* res=list1;
  
  while(list1!=NULL&&list2!=NULL)
  {
      Node *current=NULL;
      while(list1!=NULL&&list1->val<=list2->val)
      {
          current=list1;
          list1=list1->next;
      }
      current->next=list2;//setting the link to the next smaller node
      //swap
      current=list1;
      list1=list2;
      list2=current;
  }