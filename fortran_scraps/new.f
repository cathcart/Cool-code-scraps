      subroutine func(i) 
      integer::i
      print *, "The pass value is ",i
      return 
      end subroutine func

      program new
      integer::i
      i=1
      call func(i)
      print *, "hello"
      end program new
