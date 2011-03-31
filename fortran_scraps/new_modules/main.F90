      program main
      use so_example, only:subroutine_1,subroutine_2
      use so_example, only:Y
      use variables
      implicit none
      integer :: t
        print *, "hello from main"
        a=2
        print *, Y
        call subroutine_1
        call subroutine_2
        print *, a
        print *, t
      end program main
