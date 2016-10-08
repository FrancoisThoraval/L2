int Max3Nombres(int nb1, int nb2, int nb3){
    if ((nb1>nb2)&&(nb1>nb3)) {
        return nb1;
    }
    else
        if ((nb2>nb3)) {
            return nb2;
        }
        else
            return nb3;
}


int Min3Nombres(int nb1, int nb2, int nb3){
    if ((nb1<nb2)&&(nb1<nb3)) {
        return nb1;
    }
    else
        if ((nb2<nb3)) {
            return nb2;
        }
        else
            return nb3;
}
