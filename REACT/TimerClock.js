import React, { useRef, useState, useCallback } from 'react';

const ClockTimer = () => {
    const [time, setTime] = useState(0);
    const [isRunning, setIsRunning] = useState(false);
    const [isPaused, setIsPaused] = useState(false);
    const timerID = useRef(null);
    const countOfResponse = useRef(0);

    // -----------Functions------------
    const start = useCallback(() => {
        if (countOfResponse.current > 2) {
            alert("Not Allowed");
            return;
        }
        setIsRunning(true);
        setIsPaused(false);
        timerID.current = setInterval(() => {
            setTime(prev => prev + 1);
        }, 1000);
    }, []);

    const stop = useCallback(() => {
        setIsRunning(false);
        setIsPaused(false);
        clearInterval(timerID.current);
    }, []);

    const pause = useCallback(() => {
        if (countOfResponse.current > 2) {
            alert("Not Allowed");
            return;
        }
        if (timerID.current) {
            clearInterval(timerID.current);
            timerID.current = null;
            setIsPaused(true);
        } else {
            countOfResponse.current++;
            start();
        }
    }, [start]);

    const reset = useCallback(() => {
        setTime(0);
        clearInterval(timerID.current);
        setIsRunning(false);
        setIsPaused(false);
    }, []);

    return (
        <div>
            <h1>{time}</h1>
            <br />
            <button onClick={start} disabled={isRunning && !isPaused}>Start</button>
            <button onClick={stop} disabled={!isRunning && !isPaused}>Stop</button>
            <button onClick={pause} disabled={!isRunning}>Pause</button>
            <button onClick={reset}>Reset</button>
        </div>
    );
}
export default ClockTimer;
