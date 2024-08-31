bool isRunning()
{
    if (getState() == isStateIdle())
        return false;
    else
        return true;
}