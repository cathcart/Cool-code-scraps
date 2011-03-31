      subroutine to_lower(in_str,out_str)
        character(*), intent(in):: in_str
        character(*), intent(out):: out_str
        integer :: i

        out_str=in_str

        do i=1, len(in_str)
          select case(in_str(i:i))
            case("A":"Z")
              out_str(i:i)=achar(ichar(in_str(i:i))+32)
          end select
        end do
      end subroutine to_lower

      subroutine dij
        integer :: nd
        character(10) :: dummy

        open(unit=69,file="test.dat",status="old")
        read(69, *, err = 100, end = 100) nd,dummy
        print *, nd

        100 print "error"
      end subroutine dij

      program string
       ! character, dimension(:),allocatable::str,correct
        integer :: n1,n2
        character(6) :: str,correct
        integer, dimension(:),allocatable ::nang
        str="ThOmAs"

        call to_lower(str,correct)

        call dij

        print *, str
        print *, correct

        open(unit=98,file="tmp",status="old")
        read(98,*) n1,n2
        close(98)
        print *, n1, n2
        print *,max(n1,n2)
C
C        allocate(nang(6))
C        
C        do n1=1,6
C          nang(i)=n2-2*i
C        enddo       
      end program string
