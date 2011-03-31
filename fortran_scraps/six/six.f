      subroutine extra()
        print *, "a little something extra"
      end subroutine extra

      subroutine square(n,j)
        integer ::n
        integer ,intent(out)::j
        j=n*n
        !if (j .eq. 81)then
        !  call extra()
        !endif
      end subroutine 

      program six
        integer ::n
        integer :: j,sum_s,square_s

        sum_s=0
        square_s=0      
        do n=1,100
          sum_s=sum_s+n
          call square(n,j)
          square_s=square_s+j
        enddo
        call square(sum_s,j)
        !print *, "square of the sums",j
        !print *, "sum of the squares",square_s
        print *, "ans",abs(j-square_s)
      end program six
