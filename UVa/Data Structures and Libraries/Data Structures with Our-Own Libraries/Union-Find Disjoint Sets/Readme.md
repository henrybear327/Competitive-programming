# Notes

### 793

When implementing the UFDS, you need to be careful with details!!!

1. In `Union_sets()`, never write code like `data[b].rep = data[a].rep;` because
test case c 1 4, c 2 4 will get you wrong answer 
(要改rep的rep，不是路徑上的點的rep，因為這種find_set query是單向的!)
2. Use `find_set(int a)` frequently to update rep