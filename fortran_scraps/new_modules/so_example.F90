      module so_example
        implicit none
        real :: y=2.
        private
        public ::subroutine_1, subroutine_2
        public :: Y
        contains
          subroutine subroutine_1
            print *, "hello from sub_1"
          end subroutine subroutine_1
          subroutine subroutine_2
            use variables
            print *,a
            allocate(b(3))
            b(:)=a(:,1)
            print *,b
          end subroutine subroutine_2
      end module so_example
