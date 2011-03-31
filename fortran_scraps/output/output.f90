      program output

      character(70) :: header
      character(70) :: title
      integer :: some_number


      write(header,'(A)') "header text"

      title = "some text    "
      some_number = 3
      header = trim(header)//"   Hamann"

      write(title,'(A)') trim(title)

      print *, "hello"
      write(*,'(A)') header
      end program output
