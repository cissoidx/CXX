int main()
{
    int *pInt = new int[10];

    return 0; 
}

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=/home/workspace/valgrind-out.txt /home/workspace/a.out