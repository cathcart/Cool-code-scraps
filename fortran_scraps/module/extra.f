      module extra
       implicit none
       integer :: one=3

       public :: func
c       private
       contains

       subroutine func(two)
c         implicit none
          integer ,intent(in) :: two
         print *,"more"
         one=4
         print *, two
       end subroutine func

      end module extra
