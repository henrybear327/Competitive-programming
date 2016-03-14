# My UVa Online Judge Submission Code and thoughts

Just like the Codeforces repository, I will try to organize my code in a way that
it'll be easy to search and review.

> No pain, no gain.

> Work harder, or you will become the loser in this field.


# Sidenotes
#### Setting up a folder using ```git init```

If you only add new folders but no new files such as Readme.md,  ```git add```
and ```git commit``` won't work. It will throw error messages:

```
error: src refspec master does not match any.  
error: failed to push some refs to 'ssh://xxxxx.com/project.git'"
```

You can check using ```git status``` and  ```git branch```,
 you will see no branch at all!

#### When committed on the wrong date/time

```
GIT_COMMITTER_DATE="Sun Sep 5 01:54:22 2015 +0800" git commit --amend --date "Sun Sep 5 01:54:22 2015 +0800"
```
