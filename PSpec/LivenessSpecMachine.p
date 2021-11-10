spec LivenessSpecMachine observes eChanConnected{
    start state Init {
        entry{
            goto Wait;
        }
        on eChanConnected do{
            goto Done;
        }
    }

    hot state Wait {
        on eChanConnected do{
            goto Done;
        }
    }

    state Done { }
}
