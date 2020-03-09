# loldog
inspired by lolcat

# Build
  make
  
  sudo make install

# How to use?
  After install, run: 
  
  *loldog -h*

# Example
  loldog -l loldog.c LICENSE
  
  => cat loldog.c and LICENSE on the screen with color-pattern=line

# What can you do with it?
pipe: ls -l | loldog

redirect: loldog < loldog.c

via stdin: loldog
