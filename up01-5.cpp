int
main()
{
    int count;
    std::cin >> count;
    Holder *holders = new Holder[count];
    for (int i = count / 2 - 1; i >= 0; i--) {
        holders[i].swap(holders[count - i - 1]);
    }
    delete [] holders;
    return 0;
}