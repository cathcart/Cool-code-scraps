      program tmp
        real :: i,x
        i=1
        x=2
        write(*, 900) (i,i=1,10)
        900 format (F8.3)

      end program tmp
