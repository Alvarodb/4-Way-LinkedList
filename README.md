# 4-Way-LinkedList Implementation

- This  4-Way-LinkedList implementation was used for a console game in C++, the list
is fill by reading the file called **"map.txt"** and the actual internal representation
of the list after lecture can be fine in the image **"map.png"**. In the actual game, the list
represents the whole map, each character represents a different obstacle or part of the map. Of course
this implementation can be used in different topics that include this type of data structure.

- The algorithm used consisted in picking the first Node **(Red circle)** of each row in a variable, then do 
the first linked list which is the one followed by the green arrow, after that using the first Node we had saved **(Red circle)**
we get the next row first Node **(Orange circle)** as the blue arrow shows. This continues until every row is covered and linked 
in the 4-ways with the others while inserting the value of each node, in this case, each character.


![Image of map](https://github.com/Alvarodb/4-Way-LinkedList/blob/master/fourLinkedList/algorithm.png)


